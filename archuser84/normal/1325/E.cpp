#include <iostream>
#include <string.h>
#include <math.h>
#include <memory.h>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) cout<<(flag?"YES\n":"NO\n")
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

const int N = 1000001;
const int sN = 1000;

vector<int> gr[N];

// Function to add edge 
void Add_edge(int x, int y)
{
    gr[x].push_back(y);
    gr[y].push_back(x);
}

bool vis[N] = {};
int dist[N];
int par[N];
int vised[N]; int vSize = 0;
int q[N]; int qs,qe;
int shortest_cycle(int n)
{
    // To store length of the shortest cycle 
    int ans = INT_MAX;

    // For all vertices 
    for (int i = 1; i <= sN; i++) {
        
        vis[i] = true; vised[vSize++] = i;;
        dist[i] = 0;        

        // Push the source element 
        q[0] = i;
        qs = 0; qe = 1;

        // Continue until queue is not empty 
        while (qs < qe) {

            // Take the first element 
            int x = q[qs++];

            // Traverse for all it's childs 
            for (int child : gr[x]) {

                // If it is not visited yet 
                if (!vis[child]) {

                    vis[child] = true;
                    vised[vSize++] = child;
                    // Increase distance by 1 
                    dist[child] = 1 + dist[x];

                    // Change parent 
                    par[child] = x;

                    // Push into the queue 
                    q[qe++] = child;
                }

                // If it is already visited 
                else if(par[x] != child)
                    ans = min(ans, dist[x] + dist[child] + 1);
            }
        }

        Loop(i,0,vSize)
            vis[vised[i]] = false;
        vSize = 0;
    }


    // If graph contains no cycle 
    if (ans == INT_MAX)
        return -1;

    // If graph contains cycle 
    else
        return ans;
}

void ADD(int y)
{
    int x = y;
    int a = -1, b = -1;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            int cnt = 0;
            while (x % i == 0)
            {
                x /= i;
                cnt++;
            }
            if (cnt % 2)
            {
                if (a == -1)
                    a = i;
                else
                    b = i;
            }
        }
    }
    if (x > 1)
    {
        if (a == -1)
            a = x;
        else
            b = x;
    }
    if (a == -1)
        Add_edge(1, 1);
    else if (b == -1)
        Add_edge(1, a);
    else
        Add_edge(a, b);
}

int main()
{
    int n;
    cin >> n;
    Loop(i, 0, n)
    {
        int x;
        cin >> x;
        ADD(x);
    }

    cout << shortest_cycle(N);
}
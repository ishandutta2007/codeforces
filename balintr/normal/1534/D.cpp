#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, bool> pib;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<pib> vpib;
typedef int8_t int8;
typedef complex<double> cmplx;
template <typename T> using minPq = priority_queue<T, vector<T>, greater<T>>;

#define boost() cin.sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define fs first
#define sc second
#define ALL(v) (v).begin(), (v).end()
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}

const int MN = 2005;
int n;
set<int> adjList[MN];
int dist[MN];
int arr[MN];
int numAtDist[MN];
vi nodesAtDist[MN];

int qCount = 0;
void query(int n1){
    qCount++;
    assert(qCount <= (n+1)/2);

    cout << "? " << n1 + 1 << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if(arr[i] == 1){
            adjList[n1].insert(i);
            adjList[i].insert(n1);
        }
    }
}

int main(){
    cin >> n;
    int maxDist = 0;

    query(0);
    memcpy(dist, arr, n*sizeof(int));
    for (int i = 0; i < n; ++i) {
        nodesAtDist[dist[i]].pb(i);
        numAtDist[dist[i]]++;
        maxDist = max(maxDist, dist[i]);
    }

    int chain0 = 0;
    int chain1 = 0;

    for (int i = 1; i <= maxDist; ++i) {
        if(i % 2 == 0) chain0 += numAtDist[i];
        else chain1 += numAtDist[i];
    }

    int d1;
    if(chain0 < chain1) d1 = maxDist/2*2;
    else d1 = (maxDist-1)/2*2 + 1;

    while(d1 > 0){
        for(int n1 : nodesAtDist[d1]){
            query(n1);
        }
        d1 -= 2;
    }

    cout << "!\n";
    for (int i = 0; i < n; ++i) {
        for(int n2 : adjList[i]){
            if(n2 > i) cout << i+1 << ' ' << n2+1 << '\n';
        }
    }
    cout.flush();
}
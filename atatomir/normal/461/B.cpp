#include <iostream>
#include <vector>

using namespace std;

struct nod{
    bool checked;
    bool black;
    long long c0,c1;
    vector<long> neighbour;
};

#define maxN 100005
#define pb push_back
#define mod 1000000007

long n,i,x;
nod a[maxN];

void dfs(long nod){
    a[nod].checked = true;
    for(long i=0;i<a[nod].neighbour.size();i++){
        long u = a[nod].neighbour[i];
        if(a[u].checked == false) {
            dfs(u); a[u].checked = true;
            a[nod].c1 *= a[u].c0;
            a[nod].c1 += a[u].c1*a[nod].c0;
            a[nod].c0 *= a[u].c0;

            a[nod].c1 %= mod; a[nod].c0 %= mod;
        }
    }
    if(a[nod].black)
        a[nod].c1 = a[nod].c0;
    else
        a[nod].c0 += a[nod].c1;
}

int main()
{
    cin >> n;
    for(i=1;i<n;i++){
        cin >> x;
        a[i].neighbour.pb(x);
        a[x].neighbour.pb(i);
    }
    for(i=0;i<n;i++){
        cin >> x;
        if(x) a[i].black = true; else a[i].black = false;
        a[i].checked = false;
        a[i].c0 = 1; a[i].c1 = 0;
    }

    dfs(0);
    cout << a[0].c1 ;

    return 0;
}
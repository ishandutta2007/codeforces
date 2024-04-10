#include <iostream>
#include <iomanip>
#include <vector>

#define NMAX 100015
using namespace std;

struct muchie {
    int y;
    int ind;

    muchie(int y=0, int ind=0): y(y), ind(ind) {}
};

vector<muchie> graf[NMAX];

int n;
int l[NMAX];
long long int pondere[NMAX];

int din[NMAX];
void dfs(int nod,int father) {
    din[nod]=1;

    for(vector<muchie>::iterator it=graf[nod].begin();it!=graf[nod].end();it++)
        if(it->y!=father){
            dfs(it->y,nod);
            din[nod]+=din[it->y];

            pondere[it->ind]=(1ll*din[it->y]*(n-din[it->y]));
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;

    int a,b;
    for(int i=1;i<n;i++){
        cin>>a>>b>>l[i];
        graf[a].push_back(muchie(b,i));
        graf[b].push_back(muchie(a,i));
    }

    dfs(1,0);

    int q=0;
    cin>>q;

    long long int ans=0;
    for(int i=1;i<n;i++){
        ans+=l[i]*pondere[i];
    }

    int r,w;

    long long int raport=(n*(n-1ll))/2ll;
    while(q--){
        cin>>r>>w;

        ans-=l[r]*pondere[r];
        l[r]=w;
        ans+=l[r]*pondere[r];

        cout<<fixed<<setprecision(9)<<(3*ans)/((double)raport)<<'\n';
    }

    return 0;
}
#include <iostream>
#include <string>

#define A 30
#define M 107
#define f first
#define s second
#define mp make_pair

using namespace std;

string s,t,v;
int p[A][M],d[M][M][M],n,m,k;
pair<pair<int,int>,int> link[M][M][M];
bool u[M][M][M];

void read(void){
    cin>>s>>t>>v;
    n=v.length();
    m=s.length();
    k=t.length();
}

void pref(void){
    for (int i=0; i<A; ++i){
        char ch='A'+i;
        for (int j=1; j<=n; ++j)
            for (int l=min(n,j+1); l>=1; --l)
                if (v.substr(j-(l-1),l-1)+ch==v.substr(0,l)){
                    p[i][j]=l;
                    break;
                }
    }
    p[v[0]-'A'][0]=1;
}

void din(void){

    for (int i=1; i<=m; ++i)
        for (int j=1; j<=k; ++j){

            if (s[i-1]==t[j-1]){
                int c=s[i-1]-'A';
                for (int t=0; t<n; ++t){
                    int val=d[i-1][j-1][t]+1;
                    int to=p[c][t];
                    if (d[i][j][to]<val){
                        d[i][j][to]=val;
                        u[i][j][to]=1;
                        link[i][j][to]=mp(mp(i-1,j-1),t);
                    }
                }
            }

            for (int t=0; t<n; ++t){
                int val=d[i][j][t];

                if (d[i+1][j][t]<val){
                    d[i+1][j][t]=val;
                    link[i+1][j][t]=mp(mp(i,j),t);
                    u[i+1][j][t]=0;
                }

                if (d[i][j+1][t]<val){
                    d[i][j+1][t]=val;
                    link[i][j+1][t]=mp(mp(i,j),t);
                    u[i][j+1][t]=0;
                }
            }
        }
}

void kill(void){
    int ma=0,tt=0;
    string ans="";
    for (int t=0; t<n; ++t)
        if (ma<d[m][k][t]){
            ma=d[m][k][t];
            tt=t;
        }

    int i=m,j=k;
    while (d[i][j][tt]>0){
        if (u[i][j][tt])
            ans=ans+s[i-1];
        int io=link[i][j][tt].first.first;
        int jo=link[i][j][tt].first.second;
        int tto=link[i][j][tt].second;
        i=io;
        j=jo;
        tt=tto;
    }
    if (ma==0)
        cout<<"0";
    else
    for (i=ans.length()-1; i>=0; --i)
        cout<<ans[i];
    cout<<"\n";
}

int main(void){
    read();
    pref();
    din();
    kill();
    return 0;
}
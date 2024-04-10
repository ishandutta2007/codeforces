#include<bits/stdc++.h>
using namespace std;

typedef long long lala;
typedef pair<int,int> pii;

//constants
#define Pi acos(-1.0)
#define INF INT_MAX ///check it again
#define mod 1000000007ll

#define D(x) cout << #x " = "<<(x)<<endl

#define xx first
#define yy second

#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d %d",&a,&b)
#define siii(a,b,c) scanf("%d %d %d",&a,&b,&c)

#define pi(a) printf("%d\n",a)
#define psi(a) printf(" %d",a)
#define poi(a) printf("%d",a)

#define sl(a) scanf("%lld",&a)
#define pl(a) printf("%lld\n",a)

#define Nline() printf("\n")

#define sstr(str) scanf("%s",str)
#define pstr(str) printf("%s\n",str)

#define fin() freopen("in.txt","r",stdin)
#define fout() freopen("out.txt","w",stdout)

#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))

#define mx 109

int ar[mx],b[mx];
bool mark[mx];
int h[mx];
int ind[mx];
bool ok[mx];
vector<int>res;

int main()
{
    int n,m,i,j;
    int smm;
    sii(n,m);
    int x,y;
    for(i=0;i<m;i++){
        sii(x,y);
        mark[x]=true;
        h[x]=y;
        ind[x]=i+1;
    }
    for(i=1;i<=n;i++)si(ar[i]);
    int k;
    for(k=1;k<=n;k++){
        memset(ok,false,sizeof(ok));
        res.clear();
        for(i=1;i<=n;i++)b[i]=ar[i];
        bool fl;
        while(1){
            fl=false;
            for(i=1;i<=k;i++){
                if(!mark[i] || ok[i])continue;
                for(j=i,smm=h[i];j<=k;j++){
                    smm+=b[j];
                    if(smm<0){
                        break;
                    }
                }
                if(j>k){
                    fl=true;
                    ok[i]=true;
                    res.push_back(i);
                    for(j=i;j<=k;j++)b[j]=0;
                }
            }

            for(i=n;i>=k;i--){
                if(!mark[i] || ok[i])continue;
                for(j=i,smm=h[i];j>=k;j--){
                    smm+=b[j];
                    if(smm<0){
                        break;
                    }
                }
                if(j<k){
                    fl=true;
                    ok[i]=true;
                    res.push_back(i);
                    for(j=i;j>=k;j--)b[j]=0;
                }
            }
            if(!fl || res.size()==m)
                break;
        }
        if(res.size()==m){
            printf("%d\n",k);
            for(i=0;i<res.size();i++){
                if(i)printf(" ");
                printf("%d",ind[res[i]]);
            }
            puts("");
            return 0;
        }
    }
    puts("-1");

    return 0;
}
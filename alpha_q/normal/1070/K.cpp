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

#define mx 100009

int ar[mx];

vector<int>res;
int main()
{
    int n,i,j,k,sm=0;
    sii(n,k);
    for(i=0;i<n;i++){si(ar[i]);sm+=ar[i];}
    bool fl=(sm%k==0);
    k=sm/k;
    int lst=-1;
    for(i=0,sm=0; fl && i<n;i++){
        sm+=ar[i];
        if(sm==k){
            res.push_back(i-lst);
            lst=i;
            sm=0;
        }
        else if(sm>k){
            fl=false;
            break;
        }
    }
    if(sm!=0){
        fl=false;
    }
    if(fl){
        puts("Yes");
        for(i=0;i<res.size();i++){
            if(i)printf(" ");
            printf("%d",res[i]);
        }
        puts("");
    }
    else
        puts("No");
    //res.clear();
    //main();
    return 0;
}
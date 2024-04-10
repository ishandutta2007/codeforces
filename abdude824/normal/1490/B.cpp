// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 


#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long int
#define ll long long int
#define fi(n) for(int i=0;i<n;i++)
#define fj(n) for(int j=0;j<n;j++)
#define W(x) int x;cin>>x;while(x--)
#define fr(n) for(int i=n-1;i>=0;i--)
#define mp make_pair
#define fo(i,a,n) for(int i=a;i<n;i++)
#define ps(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define vi vector<int>
#define deb(x) cout<<#x<<"="<<x<<endl;
#define all(a) (a).begin(),(a).end()
#define pii pair<int,int>
#define sortall(x) sort(all(x))
#define mk(arr,n,type)  type *arr=new type[n];
#define vpi vector<pair<int,int> >
#define setbits(x) __builtin_popcountll(x)
#define zerbits(x) __builtinctzll(x)
#define mod 1000000007
#define inf 1e18
#define sz(x) (int)x.size()
#define vs vector<string>
#define itr(a) for(auto it=a.begin();it!=a.end();it++)
#define f first
#define s second
#define INT_SIZE 32
int mpow(int exp, int base);
//I don't know what the funciton aeh() does but it speeds up my mess
void aeh()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
 
int32_t main()
{
    aeh();
    int t;cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vi a(n);

        int c[3]{0};
        fi(n)
        {
            cin>>a[i];
            if(a[i]%3)
            {
                if(a[i]%3==1)
                    c[1]++;
                else
                    c[2]++;
            }
            else
                c[0]++;
        }       
        if(c[0]==c[1]&&c[1]==c[2])
        {
            cout<<0<<endl;
        }
        else{
            int x=(c[0]+c[1]+c[2])/3;
            int neg=0,pos=0;
            int arr[3];
            fi(3)
            {
                arr[i]=x-c[i];
                if(arr[i]<0){
                    neg++;
                   
                }
                else if(arr[i]>0)
                    pos++;

            }
            int ans=0;
            if(neg==2)
            {
                 if(c[0]<x)
                    {
                        ans=c[2]-x+2*(c[1]-x);
                    }
                    else if(c[1]<x)
                    {
                        ans=c[0]-x+2*(c[2]-x);
                    }
                    else{
                        ans=c[1]-x+2*(c[0]-x);
                    }
            }
            else if(pos==2)
            {

                 if(c[0]>x)
                    {
                        ans=x-c[1]+2*(x-c[2]);
                    }
                    else if(c[1]>x)
                    {
                        ans=x-c[2]+2*(x-c[0]);
                    }
                    else{
                        ans=x-c[0]+2*(x-c[1]);
                    }
            }
            else if(pos){
                    if(c[0]>x)
                    {
                        ans=x-c[1]+2*(x-c[2]);
                    }
                    else if(c[1]>x)
                    {
                        ans=x-c[2]+2*(x-c[0]);
                    }
                    else{
                        ans=x-c[0]+2*(x-c[1]);
                    }
            }
            cout<<ans<<endl;



        }
    }
}

int mpow(int base, int exp)
{
    base %= mod;
    int result = 1;
    while (exp > 0)
    {
        if (exp & 1)result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}
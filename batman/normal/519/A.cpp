//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1.2 /////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define what_is(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N (1100)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define MOD (ll)1e9+7
#define IB ios_base::sync_with_stdio;
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
//bool sortt(int x,int y){ return a[x] > a[y]; }


string s;
int a,b;
int main()
{ 
    for(int i=0;i<8;i++)
    {
        cin>>s;
        for(int j=0;j<8;j++)
        {
            switch(s[j])
            {
                case 'Q':
                    a+=9;
                    break;
                case 'R':
                    a+=5;
                    break;
                case 'B':
                    a+=3;
                    break;
                case 'N':
                    a+=3;
                    break;
                case 'P':
                    a+=1;
                    break;
                case 'q':
                    b+=9;
                    break;
                case 'r':
                    b+=5;
                    break;
                case 'b':
                    b+=3;
                    break;
                case 'n':
                    b+=3;
                    break;
                case 'p':
                    b+=1;
                    break;                                      
            }
        }
    }
    if(a>b)
        cout<<"White";
    else if(a<b)
        cout<<"Black";
    else
        cout<<"Draw";
    
    return 0;
}
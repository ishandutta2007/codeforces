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
    cin.tie(NULL);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int32_t main()
{
    aeh();
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vi a(n);
        fi(n)
        cin >> a[i];
        vi odd, ev;
        fi(n)
        {
            if(a[i] % 2)
                odd.pb(a[i]);
            else
                ev.pb(a[i]);
        }
        sortall(odd);
        sortall(ev);

        int ptr1 = ev.size() - 1, ptr2 = odd.size() - 1;
        int turn = 0;
        int al = 0, bob = 0;
        if(odd.size() && ev.size())
        {

            while(ptr1 >= 0 && ptr2 >= 0)
            {
                if(!turn)
                {
                    if(odd[ptr2] > ev[ptr1])
                    {
                        odd[ptr2] = 0;


                        ptr2--;
                    }
                    else
                    {
                        al += ev[ptr1];
                        ptr1--;
                    }
                    turn = 1;
                }
                else
                {
                    if(odd[ptr2] > ev[ptr1])
                    {

                        bob += odd[ptr2];
                        ptr2--;
                    }
                    else
                    {
                        ev[ptr1] = 0;
                        ptr1--;
                    }
                    turn = 0;
                }
            }
            for(int i=ptr1;i>=0;i--)
            {
                if(turn){
                    turn=0;
                    continue;
                }
                al+=ev[i];
                i--;
            }

            for(int i=ptr2;i>=0;i--)
            {
                if(!turn){
                    turn=1;
                    continue;
                }
                bob+=odd[i];
                i--;
            }

            if(al > bob)
                cout << "Alice" << endl;
            else if(al == bob)
                cout << "Tie" << endl;
            else
                cout << "Bob" << endl;
        }
        else{
            if(odd.size()>1)
                cout<<"Bob"<<endl;
            else if(odd.size()==1)
                cout<<"Tie"<<endl;
            else
                cout<<"Alice"<<endl;

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
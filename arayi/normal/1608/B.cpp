#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cout.tie(0);
#define str string
#define ad push_back
#define MP make_pair
#define fr first
#define sc second
#define lli long long int
#define all(x) (x).begin(), (x).end()
using namespace std;

const int N = 1e6 + 20;


int t, n, a, b;
int main()
{
    fastio;
    cin >> t;
    while (t--)
    {
        cin >> n >> a >> b;
        if(abs(a-b)>1 || a+b>n-2) 
        {
            cout<<-1<<endl;
            continue;
        }
        int i1 = n/2, i2 = n;
        if(a>b)
        {
            for (int i = 0; i < a; i++)
            {
                cout<<i+1<<" "<<n-i<<" ";
            }
            for (int i = n-a; i > a; i--) cout<<i<<" ";
            cout<<endl;
        }
        else
        {
            for (int i = 0; i < b; i++)
            {
                cout<<n-i<<" "<<i+1<<" ";
            }
            if(a<b) for (int i = b+1; i <= n-b; i++) cout<<i<<" ";
            else for (int i = n-b; i > b; i--) cout<<i<<" ";
            cout<<endl;
        }
    }
    
    return 0;
}
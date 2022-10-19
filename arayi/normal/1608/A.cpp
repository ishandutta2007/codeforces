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


int t, n;
int main()
{
    fastio;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout<<i+2<<" ";
        }
        cout << endl;
    }
    
    return 0;
}
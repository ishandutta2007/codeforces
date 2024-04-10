#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define m_p make_pair
#define get leirogoerg
#define files(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define left dogjreg
#define right dgfdogjreg

typedef long long ll;
typedef double ld;
const int arr=6e5;

signed main()
{

    vector<int> vec;
    vec.pb(1);
    vec.pb(2);
    vec.pb(3);

    int n;
    cin>>n;

    while (n--)
    {
        int a;
        cin>>a;
        if (a!=vec[0] && a!=vec[1])
        {
            cout<<"NO";
            return(0);
        }

        if (a==vec[0])
            swap(vec[1],vec[2]); else
        if (a==vec[1])
            swap(vec[0],vec[2]);
    }

    cout<<"YES";
}
/*

*/
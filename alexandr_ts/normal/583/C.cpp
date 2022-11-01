#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define SSTR(x) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 250001;
const ld EPS = 1e-8;
const int INF = 2 * 1e9 + 1;
const int MOD = 1e9 + 7;

    vector <int> nums;

int main() {
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int t;
    map <int, int> st;
    fr(i, n * n) {
        cin >> t;
        st[-t]++;
    }
    //int ans = 0;
    //for (auto it1 = st.begin(); it1 != st.end(); it1++)
        //cout << *it1 << " ";cout << endl;
    fr(i, n) {
        auto it1 = st.begin();
        while (st[it1->first] <= 0)
            it1++;
        //cout << "! ";
        nums.pb(-(it1->first));
        //cout << *it1 << endl;
        //st.erase(it1);
        st[it1->first]--;
        //it1;
        //for (auto it1 = st.begin(); it1 != st.end(); it1++)
        //cout << *it1 << " ";cout << endl;
        //cout << *it1 << endl;
        fr(j, (int)nums.size() - 1)  {
                //cout << nums[j] << " " << -(*it1) << " " << - __gcd(nums[j], -(*it1)) << endl;
            if (st[-__gcd(nums[j], -(it1->first))] > 0) {
                    st[-__gcd(nums[j], -(it1->first))]-=2;
                    //st.erase(st.find( -__gcd(nums[j], -(it1->first))));
                    //cout << nums[j] << " " << -(*it1) << " " <<  __gcd(nums[j], -(*it1)) << endl;
            }
        }
        it1 = st.begin();

               //for (auto it1 = st.begin(); it1 != st.end(); it1++)
        //cout << *it1 << " ";cout << endl;
    }
    fr(i, nums.size())
        cout << nums[i] << " ";
//    freopen("input.txt", "w", stdout);
//    cout << 500 << endl;
//    fr(i, 500 * 500)
//        cout << 1000000000 << " ";
}
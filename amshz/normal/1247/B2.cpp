#include<bits/stdc++.h>
using namespace std;
typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;
typedef pair<string , string>       pss;
#define ts(x)                       to_string(x)
#define ti(x)                       stoi(x)
#define all(x)                      (x).begin(),(x).end()
#define F                           first
#define S                           second
#define Mp                          make_pair
#define tab                         '\t'
#define sep                         ' '
#define mine(v)                     *min_element(all(v))
#define maxe(v)                     *max_element(all(v))
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
#define endl                        "\n"
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }
const int maxn = 1e5 + 10,mod = 1e9 + 7;
int main(){
    fast_io;
    //cout << fixed << setprecision(15);
    int times;cin >> times;
    for(int j = 0 ; j < times ; j++){
        int n,k,d;cin >> n >> k >> d;
        map<int,int>name;
        int inp[n];
        for(int j = 0 ; j < n ; j++)cin >> inp[j];
        int cost = 0;
        for(int i = 0 ; i < d ; i++){
            if(name[inp[i]] > 0)name[inp[i]]++;
            else{
                cost++;
                name[inp[i]] = 1;
            }
        }
        int now = cost;
        for(int j = d;j<n ; j++){
            if(name[inp[j-d]] > 1){
                name[inp[j-d]]--;
            }
            else{
                name[inp[j-d]] = 0;
                now--;
            }
            if(name[inp[j]] > 0){
                name[inp[j]]++;
            }
            else{
                now++;
                name[inp[j]] = 1;
            }
            //cout << cost << " " << now << endl;
            cost = min(cost,now);
        }
        cout << cost<<endl;


    }
}
/*
||\\    ||  ||  ||\\        //||     //\\     //||  |||||| //||  ||||||
|| \\   ||  ||  || \\      // ||    //  \\      ||      ||   ||      ||
||  \\  ||  ||  ||  \\    //  ||   //||||\\     ||    ||||   ||    ||||
||   \\ ||  ||  ||   \\  //   ||  //      \\    ||      ||   ||      ||
||    \\||  ||  ||    \\//    || //        \\   ||  ||||||   ||  ||||||
*/
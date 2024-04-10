#include<iostream>
#define rep(i,a,b) for(int i = (a); i <= (b); i++)
#define per(i,b,a) for(int i = (b); i >= (a); i--)
#define int long long
using namespace std;

signed main(){
    int a, b, c, d;
    cout<<"? 1 1\n", cout.flush();
    cin>>a;
    cout<<"? 1 1000000000\n", cout.flush();
    cin>>b;
    cout<<"? 1000000000 1000000000\n", cout.flush();
    cin>>c;
    cout<<"? 1000000000 1\n", cout.flush();
    cin>>d;

    int x = (a+2 + 1000000000ll - d-1) / 2;
    cout<<"? "<<x<<" 1\n", cout.flush();
    int y1; cin>>y1, y1++;
    int x1 = a+2-y1, x2 = y1 + 1e9 - d-1;
    int y2 = x1 + 1e9 - b-1;
    cout<<"! "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
    cout.flush();
    return 0;
}
/*
3
999999996
1999999991
999999998
*/
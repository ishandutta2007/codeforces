#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll p = 998244353;

int print(int x, int y)
{
    cout<<0<<' '<<x<<' '<<y<<endl;
    cout.flush();
    int res; cin>>res;
    return res;
}

set<int> X;
set<int> Y;

int r = -1e8;

bool checkline_x(int x)
{
    if (print(x, r)==0) {X.insert(x); return true;}
    return false; 
}

bool checkline_y(int y)
{
    if (print(r, y)==0) {Y.insert(y); return true;}
    return false; 
}

void check_i(int i)
{
    if (checkline_x(i)) checkline_y(i);
    else Y.insert(i);
}

int main()
{
    ios_base::sync_with_stdio(0);
    while (print(r, r)==0) r++;
    int cur = -1e8;
    int res = print(cur, cur);
    cur+=res;
    check_i(cur);
    while (cur<=1e8)
    {
        int cur1 = 1;
        while(cur+cur1<=1e8)
        {
            int temp = print(cur+cur1, cur+cur1);
            if (temp<cur1)
            {
                check_i(cur+cur1+temp);
                cur+=temp;
                break;
            }
            else cur1*=2;
        }
        cur+=cur1;
    }
    cout<<1<<' '<<X.size()<<' '<<Y.size()<<endl;
    for (auto it = X.begin(); it!=X.end(); it++) cout<<*it<<' ';
    cout<<endl;
    for (auto it = Y.begin(); it!=Y.end(); it++) cout<<*it<<' ';
}
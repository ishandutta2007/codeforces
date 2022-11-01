#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long overflow=(1ll<<32)-1;
	int l;
	cin >> l;
	long long x=0;
	stack<long long> s;
	stack<long long> m;
	while(l--)
    {
        string t;
        cin >> t;
        if(t=="add")
        {
            if(s.empty()) x++;
            else x+=m.top();
            if(x>overflow)
            {
                cout << "OVERFLOW!!!" << endl;
                return 0;
            }
        }
        else if(t=="for")
        {
            long long n;
            cin >> n;
            s.push(n);
            if(m.empty()) m.push(n);
            else m.push((m.top()*n<=overflow)?(m.top()*n):(overflow+1));
        }
        else
        {
            s.pop();
            m.pop();
        }
    }
    cout << x << endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const double EPS = 1E-9;
const int N=11;

struct pt {
	int x, y;
};

inline int area (pt a, pt b, pt c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

inline bool intersect_1 (int a, int b, int c, int d) {
	if (a > b)  swap (a, b);
	if (c > d)  swap (c, d);
	return max(a,c) <= min(b,d);
}

bool intersect (pt a, pt b, pt c, pt d) {
	return intersect_1 (a.x, b.x, c.x, d.x)
		&& intersect_1 (a.y, b.y, c.y, d.y)
		&& area(a,b,c) * area(a,b,d) <= 0
		&& area(c,d,a) * area(c,d,b) <= 0;
}

int n,m;
pt a[N],b[N];
int t[N]={0,1,2,3,4,5,6,7,8,9};

bool stg()
{
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<i;++j)
        {
            if(intersect(a[i],b[t[i]],a[j],b[t[j]]))
               return false;
        }
    }
    return true;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;++i)
        cin>>a[i].x>>a[i].y;
    for(int i=0;i<m;++i)
        cin>>b[i].x>>b[i].y;
    if(n!=m)
    {
        cout<<"No"<<endl;
        return 0;
    }
    do
    {
        if(stg())
        {
            cout<<"Yes"<<endl;
            return 0;
        }
    }while(next_permutation(t,t+n));
    cout<<"No"<<endl;
    return 0;
}
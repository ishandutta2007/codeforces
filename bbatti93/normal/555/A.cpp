#include <bits/stdc++.h>

using namespace std;

int n, m, k;
bool t[100001];

int main()
{
    cin >> n >> k;
    int ki=n-1;
    for(int i=0;i<k;i++) {
        cin >> m;
        int most;
        cin >> most;
        for(int j=1;j<m;j++) {
            int a;
            cin >> a;
            if(a==most+1) t[most]=true;
            ki++;
            most=a;
        }
    }
    int a=1;
    while(t[a]) { ki-=2;a++;}
    cout << ki << endl;
    return 0;
}
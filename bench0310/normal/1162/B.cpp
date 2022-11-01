#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	int a[n][m],b[n][m],c[n][m],d[n][m];
	for(int o=0;o<n;o++) for(int i=0;i<m;i++) cin >> a[o][i];
    for(int o=0;o<n;o++) for(int i=0;i<m;i++) cin >> b[o][i];
    for(int o=0;o<n;o++)
    {
        for(int i=0;i<m;i++)
        {
            c[o][i]=min(a[o][i],b[o][i]);
            d[o][i]=max(a[o][i],b[o][i]);
        }
    }
    bool ok=1;
    for(int o=0;o<n;o++) for(int i=0;i<m-1;i++) if(c[o][i]>=c[o][i+1]||d[o][i]>=d[o][i+1]) ok=0;
    for(int o=0;o<n-1;o++) for(int i=0;i<m;i++) if(c[o][i]>=c[o+1][i]||d[o][i]>=d[o+1][i]) ok=0;
    if(ok) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
	return 0;
}
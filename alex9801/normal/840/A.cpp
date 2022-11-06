#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

int arr1[200010];
int arr2[200010];
int res[200010];

vector<pair<int, int>> v;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, i;
    scanf("%d", &n);
    for(i = 0; i<n; i++)
        scanf("%d", &arr1[i]);
    for(i = 0; i<n; i++)
        scanf("%d", &arr2[i]);

    for(i = 0; i<n; i++)
        v.push_back({ arr2[i], i });
    sort(arr1, arr1+n);
    sort(v.begin(), v.end());

    for(i = 0; i<n; i++)
        res[v[i].second] = arr1[n-i-1];
    
    for(i = 0; i<n; i++)
        printf("%d ", res[i]);
    return 0;
}
#include <iostream>
#include <cstdio>

using namespace std;
int ans1[100000];
int ans2[100000];
int a[100000];
int b[100000];


int main(){
    int n, m, x, y, i, j, k = 0;
    cin >> n >> m >> x >> y;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);         
    for (i = 0; i < m; i++)
        scanf("%d", &b[i]);
    j = 0;
    for (i = 0; i < n; i++){
        while (j < m &&  a[i] - x > b[j])
            j++;
        if (j < m && a[i] - x <= b[j] && a[i] + y >= b[j]){
            ans1[k] = i;
            ans2[k] = j;
            k++;
            j++;
        }
    }
    cout << k << endl;
    for (i = 0; i < k; i++)
        printf("%d %d\n", ans1[i] + 1, ans2[i] + 1);
    
    return 0;
}
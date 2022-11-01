#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    int b[n];
    for (int i=0; i<n; i++)
        cin >> a[i]>>b[i];
    int mi, cur;
    mi = 0;
    cur = 0;
    for (int i=0;i<n; i++){
        cur -= a[i];
        cur += b[i];
        mi = max(mi,cur);
    }
    cout << mi;
    return 0;
}
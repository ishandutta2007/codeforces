#include <iostream>

using namespace std;

int t[2001], a[2001],n;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> t[i];
        a[t[i]-1]++;
    }
    a[2000]++;
    for(int i=1999; i>0;i--) {
        a[i]+=a[i+1];
    }
    for(int i=0;i<n;i++) cout << a[t[i]] << " ";

    return 0;
}
#include <iostream>
#include <set>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    set<int> s;
    int m=0;
    int arr[101];
    for(int i=0;i<101;i++) arr[i]=0;
    int temp;
    for(int i=0;i<n;i++)
    {
        cin >> temp;
        arr[temp]++;
        s.insert(temp);
    }
    for(int i=1;i<=100;i++) m=max(m,(arr[i]+k-1)/k);
    cout << max(k*m*(int)s.size()-n,0) << endl;
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int p=2003;
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    int sum=0;
    vector<int> v;
    for(int i=n-1;i>=0;i--)
    {
        arr[i]+=sum;
        int m=arr[i]%p;
        if(i!=m)
        {
            v.push_back(1);
            v.push_back(i+1);
        }
        if(i>m)
        {
            v.push_back(i-m);
            sum+=i-m;
        }
        else if(i<m)
        {
            v.push_back(2003-m+i);
            sum+=2003-m+i;
        }
    }
    v.push_back(2);
    v.push_back(n);
    v.push_back(2003);
    cout << v.size()/3 << endl;
    for(int i=0;i<(int)v.size();i+=3)
    {
        cout << v[i] << " " << v[i+1] << " " << v[i+2] << endl;
    }
    return 0;
}
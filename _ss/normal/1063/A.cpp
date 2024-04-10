#include <iostream>

using namespace std;
string s;
void qsort(int l,int r)
{
    long long i=l,j=r;
    char mid=s[(l+r)/2];
    while (i<=j)
    {
        while (s[i]<mid) i++;
        while (s[j]>mid) j--;
        if (i<=j)
        {
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
    if (i<r) qsort(i,r);
    if (j>l) qsort(l,j);
}

int main()
{
    int n;
    cin>>n;
    cin>>s;
    qsort(0,n-1);
    cout<<s;
    return 0;
}
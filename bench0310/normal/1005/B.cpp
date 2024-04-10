#include <iostream>

using namespace std;

int main()
{
    string a,b;
    cin >> a >> b;
    int idxa=a.size()-1;
    int idxb=b.size()-1;
    int cnt=0;
    while((a[idxa]==b[idxb]) && idxa>=0 && idxb>=0)
    {
        cnt++;
        idxa--;
        idxb--;
    }
    int res=(a.size()+b.size())-(2*cnt);
    cout << res << endl;
    return 0;
}
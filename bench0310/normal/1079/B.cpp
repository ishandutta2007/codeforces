#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    string str;
    cin >> str;
    int s=(int)str.size();
    int rows=(s+19)/20;
    int idx=0;
    int p=s/rows;
    bool add;
    if(s%rows) add=1;
    else add=0;
    int allowed=s%rows;
    cout << rows << " " << p+add << endl;
    for(int o=0;o<rows;o++)
    {
        int cnt=0;
        for(int i=0;i<p;i++)
        {
            cout << str[idx];
            idx++;
            cnt++;
        }
        if(idx<s&&add&&allowed)
        {
            cout << str[idx];
            idx++;
            cnt++;
            allowed--;
        }
        for(int i=cnt;i<p+add;i++) cout << "*";
        cout << endl;
    }
    return 0;
}
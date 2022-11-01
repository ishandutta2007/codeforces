#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    char arr[n][m+1];
    for(int i=0;i<n;i++) cin >> arr[i];
    int nStart=-1;
    int nCnt=0;
    int mStart=-1;
    for(int o=0;o<n;o++)
    {
        for(int i=0;i<m;i++)
        {
            if(nStart==-1 && arr[o][i]=='B')
            {
                nStart=o;
                mStart=i;
            }
            if(arr[o][i]=='B')
            {
                nCnt++;
                break;
            }
        }
    }
    cout << nStart+(nCnt-1)/2+1 << " " << mStart+(nCnt-1)/2+1 << endl;
    return 0;
}
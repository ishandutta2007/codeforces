#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[101];
    int b[101];
    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    int qua = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(a[i] == b[j])
                qua++;
    cout << qua;
}
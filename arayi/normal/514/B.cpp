#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

bool col[1010] = {false};
long double M[1010][2];
long double x, y;
long double k, m;
long long int n;
int main()
{
    cin >> n >> x >> y;
 
    for (int i = 0; i < n; i++)
    {
        cin >> M[i][0] >> M[i][1];
    }

    int sum = n;
    int i = 0;
    bool ez = false;
    while (i < n)
    {
        ez = false;
        if (col[i])
        {
            for (int x = i; x < n; x++)
            {
                if (!col[x])
                {
                    i = x;
                    break;
                }
                
            }
        }
        col[i] = true;
        if (M[i][0] - x != 0)
        {

            k = (M[i][1] - y) / (M[i][0] - x);
            m = M[i][1] - k * M[i][0];
        }
        else  ez = true;
        
        for (int j = 0; j < n; j++)
        {
            if (!col[j]) {
                if (M[j][0] == x){
                    if (ez) {
                        col[j] = true;
                        sum--;
                    }
                }
                else if ((M[j][1] - y) / (M[j][0] - x) == k){

                    col[j] = true;
                    sum--;

                }
            }
        }
        i++;
    }

    cout << sum;

}
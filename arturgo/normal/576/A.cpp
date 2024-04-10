#include <iostream>
#include <vector>
using namespace std;

int premiers[10000];

void elimine()
{
    premiers[0] = true;
    premiers[1] = true;
    for(int i = 2;i < 10000;i++)
        if(!premiers[i])
            for(int j = 2 * i;j < 10000;j += i)
                premiers[j] = true;
}

int main()
{
    int sup;
    cin >> sup;
    
    elimine();
    
    vector<int> bes;
    for(int i = 1;i <= sup;i++)
        if(!premiers[i])
        {
            int puis = i;
            while(puis <= sup)
            {
                bes.push_back(puis);
                puis *= i;
            }
        }
    
    cout << bes.size() << endl;
    for(int i = 0;i < (int)bes.size();i++)
        cout << bes[i] << " ";
    return 0;
}
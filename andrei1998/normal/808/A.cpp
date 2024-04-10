#include <iostream>
#include <vector>

using namespace std;

vector <int> gen = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, };
vector <int> gen2;

int main()
{
    for (auto it: gen)
        for (int i = 1; i <= 9; ++ i)
            gen2.push_back(it * i);
    gen2.push_back(1000000000);
    gen2.push_back(2000000000);

    int N;
    cin >> N;
    ++ N;

    int ans = 0;
    while (gen2[ans] < N)
        ++ ans;

    cout << gen2[ans] - N + 1<< '\n';
    return 0;
}
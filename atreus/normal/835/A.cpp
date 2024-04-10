#include <iostream>
#include <string>

using namespace std;

int main ()
{
    int nafar1, nafar2, s, v1, v2, t1, t2;
    cin >> s >> v1 >> v2 >> t1 >> t2;
    nafar1 = (s * v1) + (2 * t1);
    nafar2 = (s * v2) + (2 * t2);
    if (nafar2 > nafar1)
        cout << "First" << endl;
    else if (nafar1 > nafar2)
        cout << "Second" << endl;
    else
        cout << "Friendship" << endl;


}
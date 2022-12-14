#include <iostream>
#include <map>
#include <vector>

using namespace std;

string s;

bool kdominated(int k){
	map <int, int> mp;
	int l = 0;
    for (int i = 0; i < 26; i ++){
        int inx = -1;
        bool cur = true;
        for (int j = 0; j < s.size(); j ++){
            char c = i + 'a';
            if (s[j] == c){
                inx = j;
            }
            if (j - inx >= k){
                cur = false;
                break;
            }
        }
        if (cur == true)
            return true;
    }
	return false;
}

int main(){
	cin >> s;
	int l = 0, r = s.size();
	while (r - l > 1){
		int k = (r + l) / 2;
		if (kdominated(k))
			r = k;
		else
			l = k;
	}
	cout << r << endl;
}
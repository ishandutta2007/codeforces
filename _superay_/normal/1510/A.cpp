#include <bits/stdc++.h>
using namespace std;
char str[105];
int len, match[105];
vector<string> Letter(int l, int r) {
	vector<string> ret;
	ret.push_back((string)"+" + string(r - l + 3, '-') + "+");
	ret.push_back((string)"+ " + string(str + l, str + r + 1) + " +");
	ret.push_back((string)"+" + string(r - l + 3, '-') + "+");
	return ret;
}
vector<string> Tao(vector<string> cur, char ty) {
	vector<string> ret;
	if (ty == '+') {
		for (int i = 0; i < (int)cur.size(); i++) {
			if (i == 0) ret.push_back((string)"   " + cur[i] + "   ");
			else if (i == 1) ret.push_back((string)"+->" + cur[i] + "->+");
			else ret.push_back((string)"|  " + cur[i] + "  |");
		}
		ret.push_back((string)"|" + string(cur[0].size() + 4, ' ') + "|");
		ret.push_back((string)"+<" + string(cur[0].size() + 3, '-') + "+");
	} else if (ty == '?') {
		ret.push_back(string(cur[0].size() + 6, ' '));
		ret.push_back((string)"+" + string(cur[0].size() + 3, '-') + ">+");
		ret.push_back((string)"|" + string(cur[0].size() + 4, ' ') + "|");
		for (int i = 0; i < (int)cur.size(); i++) {
			if (i == 0) ret.push_back((string)"|  " + cur[i] + "  |");
			else if (i == 1) ret.push_back((string)"+->" + cur[i] + "->+");
			else ret.push_back((string)"   " + cur[i] + "   ");
		}
	} else {
		ret.push_back(string(cur[0].size() + 6, ' '));
		ret.push_back((string)"+" + string(cur[0].size() + 3, '-') + ">+");
		ret.push_back((string)"|" + string(cur[0].size() + 4, ' ') + "|");
		for (int i = 0; i < (int)cur.size(); i++) {
			if (i != 1) ret.push_back((string)"|  " + cur[i] + "  |");
			else ret.push_back((string)"+->" + cur[i] + "->+");
		}
		ret.push_back((string)"|" + string(cur[0].size() + 4, ' ') + "|");
		ret.push_back((string)"+<" + string(cur[0].size() + 3, '-') + "+");
	}
	return ret;
}
vector<string> solveexpr(int, int);
vector<string> solveterm(int l, int r) {
	if (str[l] == '(' && str[r] == ')' && match[l] == r) return solveexpr(l + 1, r - 1);
	vector<vector<string> > buck;
	for (int i = l, j; i <= r; i = j) {
		vector<string> cur;
		if (str[i] == '(') {
			j = match[i] + 1;
			cur = solveexpr(i, j - 1);
		} else {
			assert(isupper(str[i]));
			for (j = i; j <= r && isupper(str[j]); j++);
			if (i + 1 < j && j <= r && (str[j] == '+' || str[j] == '?' || str[j] == '*')) j--;
			cur = Letter(i, j - 1);
		}
		for (; j <= r && (str[j] == '+' || str[j] == '?' || str[j] == '*'); j++) {
			cur = Tao(cur, str[j]);
		}
		buck.push_back(cur);
	}
	int mxh = 0;
	for (int i = 0; i < (int)buck.size(); i++) {
		mxh = max(mxh, (int)buck[i].size());
	}
	vector<string> ret(mxh, "");
	for (int r = 0; r < mxh; r++) {
		for (int i = 0; i < (int)buck.size(); i++) {
			ret[r] += (r < (int)buck[i].size() ? buck[i][r] : string(buck[i][0].size(), ' '));
			if (i < (int)buck.size() - 1) {
				if (r == 1) ret[r] += "->";
				else ret[r] += "  ";
			}
		}
	}
	return ret;
}
vector<string> solveexpr(int l, int r) {
	vector<int> vec;
	for (int i = l, dep = 0; i <= r; i++) {
		if (str[i] == '(') dep++;
		else if (str[i] == ')') dep--;
		else if (str[i] == '|' && !dep) {
			vec.push_back(i);
		}
	}
	if (!vec.size()) return solveterm(l, r);
	vector<vector<string> > buck;
	vec.push_back(r + 1);
	for (int i = 0, lst = l; i < (int)vec.size(); i++) {
		buck.push_back(solveterm(lst, vec[i] - 1));
		lst = vec[i] + 1;
	}
	int mxw = 0;
	for (int i = 0; i < (int)buck.size(); i++) {
		mxw = max(mxw, (int)buck[i][0].size());
	}
	vector<string> ret;
	for (int i = 0; i < (int)buck.size(); i++) {
		for (int j = 0; j < (int)buck[i].size(); j++) {
			if ((i > 0 && i < (int)buck.size() - 1) || (i == 0 && j >= 1) || (i == (int)buck.size() - 1 && j <= 1)) {
				if (j != 1) ret.push_back((string)"|  " + buck[i][j] + string(mxw - buck[i][j].size() + 2, ' ') + "|");
				else ret.push_back((string)"+->" + buck[i][j] + string(mxw - buck[i][j].size() + 1, '-') + ">+");
			} else {
				ret.push_back((string)"   " + buck[i][j] + string(mxw - buck[i][j].size() + 3, ' '));
			}
		}
		if (i < (int)buck.size() - 1) ret.push_back((string)"|" + string(mxw + 4, ' ') + "|");
	}
	return ret;
}
int main() {
	scanf("%s", str);
	len = strlen(str);
	vector<int> stk;
	for (int i = 0; i < len; i++) {
		if (str[i] == '(') {
			stk.push_back(i);
		} else if (str[i] == ')') {
			int j = stk.back(); stk.pop_back();
			match[i] = j;
			match[j] = i;
		}
	}
	vector<string> ans = solveexpr(0, len - 1);
	for (int i = 0; i < (int)ans.size(); i++) {
		if (i != 1) ans[i] = (string)"   " + ans[i] + "   ";
		else ans[i] = (string)"S->" + ans[i] + "->F";
	}
	printf("%d %d\n", (int)ans.size(), (int)ans[0].size());
	for (auto &s : ans) {
		printf("%s\n", s.c_str());
	}
	return 0;
}
var l = readline().split(' ');
var n = +l[0];
var a = readline().split(' ').map(function(v){return +v;});
var b = new Array(n);
for(var i = 0; i < n; i++) {
    b[i] = [a[i], i];
}
function sortB(p,q) {
    return p[0] - q[0];
}
b.sort(sortB);

var p = new Array(n);
for(var i = 0; i < n; i++) {
	p[i] = b[i][1];
}

var chk = new Array(n);
var ansn = 0;
var ans = new Array(n);
for(var i = 0; i < n; i++) {
	if(chk[i] === undefined) {
		chk[i] = true;
		ans[ansn] = [i+1];
		for(var j = p[i]; j != i; j = p[j]) {
			chk[j] = true;
			ans[ansn].push(j+1);
		}
		ansn += 1;
	}
}

print(ansn);
for(var i = 0; i < ansn; i++) {
	print(ans[i].length + " " + ans[i].join(" "));
}
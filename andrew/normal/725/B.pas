program O_O;
var
	m,n,ans,k:int64;
	a:array['a'..'f'] of longint;
	s:string;
begin
	a['a']:=4;
	a['b']:=5;
	a['c']:=6;
	a['d']:=3;
	a['e']:=2;
	a['f']:=1;
	readln(s);
	m:=a[s[length(s)]];
	delete(s,length(s),1);
	val(s,n);
	ans:=((n-1)div 4)*16+((n+1) mod 2)*7;
	inc(ans,m);	
	writeln(ans);
end.
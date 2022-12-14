var
 a:array[1..200000] of longint;
 i,n:longint;
procedure swap(var a,b:longint);
var c:longint;
begin
 c:=a;
 a:=b;
 b:=c;
end;
begin
 readln(n);
 for i:=1 to n do read(a[i]);
 for i:=1 to n div 2 do if i mod 2=1 then swap(a[i],a[n-i+1]);
 for i:=1 to n do write(a[i],' ');
end.
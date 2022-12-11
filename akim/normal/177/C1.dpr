var a:array[1..2000,1..2000]of boolean;
    x:array[1..2000]of boolean;
    y,z:array[1..2000]of integer;
    n,m,k,l,i,yy,max:longint;
procedure dfs(q:longint);
var i:longint;
begin
 x[q]:=true;
 y[q]:=yy;inc(z[yy]);
 for i:=1 to n do
  if (a[q,i])and(not(x[i])) then dfs(i);
end;
begin
 readln(n,m);yy:=0;
 for i:=1 to m do
 begin
  readln(k,l);
  a[k,l]:=true;
  a[l,k]:=true;
 end;
 for i:=1 to n do
  if not(x[i]) then begin inc(yy);dfs(i);end;
 readln(m);
 for i:=1 to m do
 begin
  readln(k,l);
  if y[k]=y[l] then z[y[l]]:=0;
 end;
 max:=0;
 for i:=1 to n do
  if max<z[i] then max:=z[i];
 writeln(max);
end.
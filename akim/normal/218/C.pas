var a:array[1..100,1..100]of boolean;
    b:array[1..100,1..2]of longint;
    x:array[1..100]of boolean;
    n,i,f,q:longint;
procedure dfs(q:longint);
var i:longint;
begin
 x[q]:=true;
 for i:=1 to n do
  if (a[q,i])and(not(x[i])) then dfs(i);
end;
begin
 readln(n);
 for i:=1 to n do
 begin
  read(b[i,1],b[i,2]);
  for f:=i-1 downto 1 do
   if (b[i,1]=b[f,1])or(b[i,2]=b[f,2]) then begin a[i,f]:=true;a[f,i]:=true;end;
 end;
 q:=-1;
 for i:=1 to n do
  if not(x[i]) then begin inc(q);dfs(i);end;
 writeln(q);
end.
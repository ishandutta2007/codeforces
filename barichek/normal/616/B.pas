uses math;
var
  a:array[1..100,1..100]of longint;
  mini:array[1..100]of longint;
  n,m,ans:longint;
  i,j:longint;
begin
  read(n,m);
  for i:=1 to n do
    for j:=1 to m do
      read(a[i,j]);

  for i:=1 to n do
    begin
      mini[i]:=maxlongint;
      for j:=1 to m do
        mini[i]:=min(mini[i],a[i,j]);
    end;

  for i:=2 to n do
    mini[1]:=max(mini[1],mini[i]);

  writeln(mini[1]);
end.
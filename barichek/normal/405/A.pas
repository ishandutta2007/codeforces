uses math;
var
  a,b:array[1..1000]of longint;
  n,maxa:longint;
  i,j:longint;
begin
  read(n);
  for i:=1 to n do
    read(a[i]);
  for i:=n downto 1 do
    begin
      maxa:=0;
      for j:=1 to n do
        maxa:=max(maxa,a[j]);
      b[i]:=maxa;
      for j:=1 to n do
        if a[j]=maxa then begin a[j]:=0; break; end;
    end;
  for i:=1 to n do
    write(b[i],' ');
end.
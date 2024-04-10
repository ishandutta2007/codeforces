var a:array[1..8] of array[1..8] of integer;
ans, ii, jj, k, i, j:integer;
s:array[1..8] of string;
begin
k:=4;
for i:=1 to 3 do begin
  for j:=1 to 2 do
    a[i*2-1][j]:=k-1;
  for j:=4 to 5 do
    a[i*2-1][j]:=k;
  for j:=7 to 8 do
    a[2*i-1][j]:=k-1;
  a[2*i-1][3]:=-1;
  a[2*i-1][6]:=-1;
  k:=k-1;
end;
for i:=1 to 3 do 
  for j:=1 to 8 do
    a[2*i][j]:=a[2*i-1][j];
ans:=-1;
for i:=1 to 6 do begin
  readln(s[i]);
  for j:=1 to 8 do
    if ((s[i][j]='.') and (ans<a[i][j])) then  begin
      ans:=a[i][j];
      ii:=i; jj:=j;
    end;
end;
for i:=1 to 6 do begin
  for j:=1 to 8 do 
    if ((i<>ii) or (j<>jj)) then 
      write(s[i][j])
    else
      write('P');
    writeln;
  end;
end.
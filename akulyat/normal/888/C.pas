Program Trouble;
const b=26;
var mini,i,j,ti:longint;
    s:string;
    mas:array[1..b]of array[0..100001]of longint;
    ind:array[0..100005]of longint;
    min:array[1..b]of longint;
begin
readln(s);
for i:=1 to b do
  begin
  mas[i][0]:=0;
  ind[i]:=0;
  end;

for i:=1 to length(s) do
  begin
  ti:=ord(s[i])-ord('a')+1;
  inc(ind[ti]);
  mas[ti][ind[ti]]:=i;
  end;
for i:=1 to b do
  begin
  inc(ind[i]);
  mas[i][ind[i]]:=length(s)+1;
  end;

mini:=length(s);
for i:=1 to b do
  begin
  min[i]:=mas[i][1]-mas[i][0];
  for j:=2 to ind[i] do
    if mas[i][j]-mas[i][j-1]>min[i] then
      min[i]:=mas[i][j]-mas[i][j-1];
  if min[i]<mini then
    mini:=min[i];
  end;
writeln(mini);

end.
Program Choteasy;
var i,j,n,s,otv:integer;
    fort,k:int64;
    h:array[0..1001]of int64;

begin
read(n,k);
for i:=1 to n do
  read(h[i]);
for i:=1 to n do
  for j:=1 to n-1 do
    if h[j]>h[j+1] then
      begin
      fort:=h[j];
      h[j]:=h[j+1];
      h[j+1]:=fort;
      end;
s:=1;
while (k>=h[s]) and (s<n) do
  inc(s);

while 2*k<h[s] do
  begin
  k:=k*2;
  inc(otv);
  end;
  
h[s-1]:=k;
for i:=s-1 to n-1 do
  while 2*h[i]<h[i+1] do
    begin
    h[i]:=h[i]*2;
    inc(otv);
    end;     
write(otv);   

end.
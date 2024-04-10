uses math;
var
  a:array[1..10000]of longint;
  n,maxi,mini:longint;
  i:longint;
begin
  read(n);
  for i:=1 to n do
    read(a[i]);

  maxi:=a[1];
  for i:=2 to n do
    maxi:=max(maxi,a[i]);
  mini:=a[1];
  for i:=2 to n do
    mini:=min(mini,a[i]);
  for i:=1 to n do
    if a[i]=maxi then begin maxi:=i; break; end;
  for i:=n downto 1 do
    if a[i]=mini then begin mini:=i; break; end;
  if maxi>mini then writeln(maxi+n-mini-2);
  if maxi<mini then writeln(maxi+n-mini-1);
  if maxi=mini then writeln(0);
end.
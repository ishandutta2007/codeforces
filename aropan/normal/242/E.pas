uses math;
const maxn=131100;
var a,s:array[-1..20,0..maxn*2] of longint;
    pow:array[-1..20] of int64;
    ans:int64;
    n1,i,j,l,r,x,n,m,q:longint;

procedure modify(i, v, l1, r1, l, r: longint);
var
    m: longint;
begin
    if (l <= l1) and (r1 <= r) then
    begin
        inc(s[i, v]);
        a[i, v] := (r1 - l1 + 1) - a[i, v];
        exit;
    end;
    m := (l1 + r1) shr 1;
    if (l <= m) then
        modify(i, v * 2 + 0, l1, m, l, r);
    if (m < r) then
        modify(i, v * 2 + 1, m + 1, r1, l, r);
    a[i, v] := a[i, v * 2 + 0] + a[i, v * 2 + 1];
    if s[i, v] and 1 = 1 then
        a[i, v] := (r1 - l1 + 1) - a[i, v];
end;

function find(i, s1, v, l1, r1, l, r: longint): longint;
var
    res, m: longint;
begin
    if (l <= l1) and (r1 <= r) then 
    begin
        if s1 and 1=0 
            then exit(a[i, v])
            else exit((r1 - l1 + 1) - a[i, v]);
    end;
    s1 := s1 + s[i, v];
    m := (l1 + r1) shr 1;
    res := 0;
    if (l <= m) then
        res := res + find(i, s1, v * 2 + 0, l1, m, l, r);
    if (m < r) then
        res := res + find(i, s1, v * 2 + 1, m + 1, r1, l, r);
    find := res;
end;

BEGIN
readln(n1);
n:=1;
while n<n1 do n:=n*2;
pow[0]:=1;
for i:=1 to 19 do pow[i]:=pow[i-1]*2;
for i:=1 to n1 do 
  begin
  read(x);
  j:=0;
  while x>0 do
    begin
    if x and 1=1 then a[j,i+n-1]:=1;
    inc(j);
    x:=x shr 1;
    end;
  end;
for i:=0 to 19 do
  for j:=n-1 downto 1 do
    begin
    a[i,j]:=a[i,j*2]+a[i,j*2+1];
    end;
readln;
readln(m);
for q:=1 to m do
  begin
  ans:=0;
  read(x);
  if x=1
    then
      begin
      readln(l,r);
      for i:=0 to 19 do ans:=ans+(int64(find(i,0,1,1,n,l,r))*pow[i]);
      writeln(ans);
      end
    else 
      begin
      readln(l,r,x);
      i:=0;
      while x>0 do
        begin
        if x and 1=1 then modify(i,1,1,n,l,r);
        inc(i);
        x:=x shr 1;
        end;
      end;
  end;
END.
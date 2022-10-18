uses math;
var
  a:array[1..10000]of char;
  l,r:array[1..10000]of longint;
  n,ans1,ans2,fula:longint;
  i,j:longint;
begin
  readln(n);
  for i:=1 to n do
    readln(a[i],l[i],r[i]);

  for i:=1 to 366 do
    begin
      ans1:=0;
      ans2:=0;
      for j:=1 to n do
        if (a[j]='M') and (l[j]<=i) and (r[j]>=i) then inc(ans1)
        else if (a[j]='F') and (l[j]<=i) and (r[j]>=i) then inc(ans2);
      fula:=max(fula,min(ans1,ans2));
    end;

  writeln(fula*2);
end.
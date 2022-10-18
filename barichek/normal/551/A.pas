uses math;
var
  m:array[1..2000]of longint;
  i,o,n,a,ans:longint;
begin
  read(n);
  ans:=1;

  for i:=1 to n do
    begin
      read(a);
      m[i]:=a;
    end;

  for i:=1 to n do
    begin
      ans:=1;
      for o:=1 to n do
          if m[i]<m[o] then inc(ans);
      write(ans,' ');
    end;
end.
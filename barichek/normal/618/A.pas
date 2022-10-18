uses math;
var
  a:array[0..100000]of longint;
  n:longint;
  ans:longint;
  i:longint;
begin
  read(n);
  for i:=1 to n do
    begin
      inc(ans);
      a[ans]:=1;
      while a[ans]=a[ans-1] do
        begin
          a[ans-1]:=a[ans]+1;
          dec(ans);
        end;
    end;

  for i:=1 to ans do
    write(a[i],' ');
end.
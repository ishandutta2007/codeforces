uses math;
var
  n:int64;
  i,j,o:longint;
begin
  read(n);
  i:=1;
  j:=n;
  for o:=1 to n div 2 do
    begin
      write(i,' ',j,' ');
      inc(i);
      dec(j);
    end;
  if n mod 2=1 then write(n div 2+1);
end.
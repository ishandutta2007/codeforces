uses math;
var
  n,d,ans:longint;
  i,j:longint;
begin
  read(n);
  ans:=0;
  d:=0;
  for i:=1 to n do
    begin
      read(j);
      if j=-1 then
        begin
          dec(d);
          if d<0 then
            begin
              inc(ans);
              inc(d);
            end;
        end
      else inc(d,j);
    end;
  writeln(ans);
end.
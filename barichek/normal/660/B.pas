uses math;
var
  a:array[1..1000000,1..4]of longint;
  n,m:longint;
  i,j,h:longint;
begin
  read(n,m);
  i:=1;
  j:=1;
  h:=1;
  while h<>m+1 do
    begin
      a[i,j]:=h;
      if j=1 then j:=4
      else if j=2 then j:=3
      else if j=3 then
        begin
          if i<>n then begin inc(i); j:=2; end
          else if i=n then break;
        end
      else
        begin
          if i<>n then begin inc(i); j:=1; end
          else if i=n then begin i:=1; j:=2; end;
        end;
      inc(h);
    end;


  h:=0;
  for i:=1 to n do
    begin
      if a[i,2]<>0 then
        begin
          write(a[i,2],' ');
          inc(h);
          if h=m then break;
        end;
      if a[i,1]<>0 then
        begin
          write(a[i,1],' ');
          inc(h);
          if h=m then break;
        end;
      if a[i,3]<>0 then
        begin
          write(a[i,3],' ');
          inc(h);
          if h=m then break;
        end;
      if a[i,4]<>0 then
        begin
          write(a[i,4],' ');
          inc(h);
          if h=m then break;
        end;
    end;
end.
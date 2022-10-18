uses math;
var
  a:array[1..10000]of longint;
  n,km,kp,nm,np,nm1,nm2:longint;
  i,j,h:longint;
begin
  read(n);
  nm1:=0;
  nm2:=0;
  np:=0;
  for i:=1 to n do
    read(a[i]);
  for i:=1 to n do
    begin
      if a[i]>0 then inc(kp);
      if a[i]<0 then inc(km);
    end;

  write(1,' ');
  for i:=1 to n do
    if a[i]<0 then
      begin
        nm:=i;
        write(a[i]);
        writeln;
        break;
      end;

  if kp>0 then
    begin
      write(1,' ');
      for i:=1 to n do
        if a[i]>0 then
          begin
            np:=i;
            write(a[i],' ');
            break;
          end;
    writeln;
    write(n-2,' ');
    end
  else
    begin
      write(2,' ');
      for i:=1 to n do
        begin
          if (a[i]<0) and (i<>nm) and (h=0) then
            begin
              nm1:=i;
              h:=1;
              write(a[i],' ');
              continue;
            end;
          if (a[i]<0) and (i<>nm) and (h=1) then
            begin
              nm2:=i;
              write(a[i],' ');
              break;
            end;
        end;
      writeln;
      write(n-3,' ');
    end;
  for i:=1 to n do
    if (i<>np) and (i<>nm) and (i<>nm1) and (i<>nm2)
      then write(a[i],' ');
end.
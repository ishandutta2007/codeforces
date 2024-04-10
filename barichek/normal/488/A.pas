uses math;
var
  a,av:longint;
  i,iv,h:longint;
begin
  read(a);
  if a<0 then
    begin
      av:=abs(a);
      for i:=av-1 downto 0 do
        begin
          iv:=i;
          h:=0;
          repeat
            if iv mod 10=8 then begin h:=1; break; end;
            iv:=iv div 10;
          until iv=0;
          if h=1 then begin writeln(abs(i-av)); halt; end;
        end;
    end;
  if a<0 then begin
    i:=1;
    repeat
      iv:=i;
      h:=0;
      repeat
        if iv mod 10=8 then begin h:=1; break; end;
        iv:=iv div 10;
      until iv=0;
      if (h=1) and (i>a) then begin writeln(i-a); halt; end;
      inc(i);
    until i=8888888888;
              end
  else
    begin
    i:=a+1;
    repeat
      iv:=i;
      h:=0;
      repeat
        if iv mod 10=8 then begin h:=1; break; end;
        iv:=iv div 10;
      until iv=0;
      if (h=1) and (i>a) then begin writeln(i-a); halt; end;
      inc(i);
    until i=8888888888;
    end;
end.
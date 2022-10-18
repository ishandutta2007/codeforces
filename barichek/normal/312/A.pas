uses math;
var
  s,smod1,smod2:string;
  n:longint;
  i:longint;
begin
  readln(n);

  for i:=1 to n do
    begin
      readln(s);
      smod1:=copy(s,1,5);
      smod2:=copy(s,length(s)-4,5);
      if (smod1='miao.') and (smod2='lala.') then begin writeln('OMG>.< I don''t know!'); continue; end;
      if smod1='miao.' then begin writeln('Rainbow''s'); continue; end;
      if smod2='lala.' then begin writeln('Freda''s');   continue; end;
      writeln('OMG>.< I don''t know!');
    end;
end.
program code4;

{$APPTYPE CONSOLE}

uses
  SysUtils;
type int=integer;
var w:int;

procedure readdata;
begin
 readln(w)
end;

procedure solve;
begin

end;

procedure writedata;
begin
 if (w mod 2=0)and(w<>2) then writeln('YES')
  else writeln('NO')
end;

begin
 //reset(input,'input.txt');
 //rewrite(output,'output.txt');
 readdata;
 solve;
 writedata
end.
var
  n, x, k: longint;
  s: string;

begin
  readln(s);
  read(n);
  if s = 'January' then k := 1;
  if s = 'February' then k := 2;
  if s = 'March' then k := 3;
  if s = 'April' then k := 4;

  if s = 'May' then k := 5;
  if s = 'June' then k := 6;
  if s = 'July' then k := 7;
  if s = 'August' then k := 8;

  if s = 'September' then k := 9;
  if s = 'October' then k := 10;
  if s = 'November' then k := 11;
  if s = 'December' then k := 12;

  x := (n + k) mod 12;


  if x = 1 then writeln('January');
  if x = 2 then writeln('February');
  if x = 3 then writeln('March');
  if x = 4 then writeln('April');
  if x = 5 then writeln('May');
  if x = 6 then writeln('June');
  if x = 7 then writeln('July');
  if x = 8 then writeln('August');
  if x = 9 then writeln('September');
  if x = 10 then writeln('October');
  if x = 11 then writeln('November');
  if x = 0 then writeln('December');



end.